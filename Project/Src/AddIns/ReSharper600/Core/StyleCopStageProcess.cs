﻿// --------------------------------------------------------------------------------------------------------------------
// <copyright file="StyleCopStageProcess.cs" company="http://stylecop.codeplex.com">
//   MS-PL
// </copyright>
// <license>
//   This source code is subject to terms and conditions of the Microsoft 
//   Public License. A copy of the license can be found in the License.html 
//   file at the root of this distribution. If you cannot locate the  
//   Microsoft Public License, please send an email to dlr@microsoft.com. 
//   By using this source code in any fashion, you are agreeing to be bound 
//   by the terms of the Microsoft Public License. You must not remove this 
//   notice, or any other, from this software.
// </license>
// <summary>
//   Stage Process that execute the Microsoft StyleCop against the
//   specified file.
// </summary>
// --------------------------------------------------------------------------------------------------------------------
namespace StyleCop.ReSharper600.Core
{
    #region Using Directives

    using System;
    using System.Collections.Generic;
    using System.Diagnostics;
    using System.Linq;

    using JetBrains.ReSharper.Daemon;
    using JetBrains.ReSharper.Psi;
    using JetBrains.ReSharper.Psi.CSharp;
    using JetBrains.ReSharper.Psi.ExtensionsAPI.Tree;
    using JetBrains.ReSharper.Psi.Tree;

    using StyleCop.Diagnostics;
    using StyleCop.ReSharper600.Options;

    #endregion

    /// <summary>
    ///   Stage Process that execute the Microsoft StyleCop against the specified file.
    /// </summary>
    /// <remarks>
    ///   This type is created and executed every time a .cs file is modified in the IDE.
    /// </remarks>
    public class StyleCopStageProcess : IDaemonStageProcess
    {
        #region Constants

        /// <summary>
        ///   Defines the max performance value - this is used to reverse the settings.
        /// </summary>
        private const int MaxPerformanceValue = 9;

        #endregion

        #region Static Fields

        /// <summary>
        ///   Used to reduce the number of calls to StyleCop to help with performance.
        /// </summary>
        private static Stopwatch performanceStopWatch;

        /// <summary>
        ///   Allows us to run the StyleCop analyzers.
        /// </summary>
        private static StyleCopRunnerInt styleCopRunnerInternal = new StyleCopRunnerInt();

        #endregion

        #region Fields

        private readonly IDaemonProcess daemonProcess;

        #endregion

        #region Constructors and Destructors

        /// <summary>
        /// Initializes a new instance of the StyleCopStageProcess class, using the specified <see cref="IDaemonProcess"/> .
        /// </summary>
        /// <param name="daemonProcess">
        /// <see cref="IDaemonProcess"/> to execute within. 
        /// </param>
        public StyleCopStageProcess(IDaemonProcess daemonProcess)
        {
            StyleCopTrace.In(daemonProcess);

            this.daemonProcess = daemonProcess;

            InitialiseTimers();

            StyleCopTrace.Out();
        }

        #endregion

        #region Public Properties

        /// <summary>
        ///   Gets the Daemon Process.
        /// </summary>
        public IDaemonProcess DaemonProcess
        {
            get
            {
                return this.daemonProcess;
            }
        }

        #endregion

        #region Public Methods and Operators

        /// <summary>
        /// The execute.
        /// </summary>
        /// <param name="committer">
        /// The committer.
        /// </param>
        public void Execute(Action<DaemonStageResult> committer)
        {
            StyleCopTrace.In();

            // inverse the performance value - to ensure that "more resources" actually evaluates to a lower number
            // whereas "less resources" actually evaluates to a higher number. If Performance is set to max, then execute as normal.
            if ((StyleCopOptions.Instance.ParsingPerformance == StyleCopStageProcess.MaxPerformanceValue)
                || (performanceStopWatch.Elapsed > new TimeSpan(0, 0, 0, StyleCopStageProcess.MaxPerformanceValue - StyleCopOptions.Instance.ParsingPerformance)))
            {
                if (this.daemonProcess.InterruptFlag)
                {
                    return;
                }

                if (!this.FileIsValid())
                {
                    return;
                }

                styleCopRunnerInternal.Execute(this.daemonProcess.SourceFile.ToProjectFile(), this.daemonProcess.Document);

                List<HighlightingInfo> violations =
                    (from info in styleCopRunnerInternal.ViolationHighlights
                     let range = info.Range
                     let highlighting = info.Highlighting
                     select new HighlightingInfo(range, highlighting)).ToList();

                committer(new DaemonStageResult(violations));

                ResetPerformanceStopWatch();
            }

            StyleCopTrace.Out();
        }

        #endregion

        #region Methods

        /// <summary>
        ///   Initializes the static timers used to regulate performance of file scavenging and execution of StyleCop analysis.
        /// </summary>
        private static void InitialiseTimers()
        {
            if (performanceStopWatch == null)
            {
                performanceStopWatch = Stopwatch.StartNew();
                performanceStopWatch.Start();
            }
        }

        /// <summary>
        ///   Resets the Performance Stopwatch.
        /// </summary>
        private static void ResetPerformanceStopWatch()
        {
            performanceStopWatch.Reset();
            performanceStopWatch.Start();
        }

        private bool FileIsValid()
        {
            PsiManager manager = PsiManager.GetInstance(this.daemonProcess.Solution);

            if (!this.daemonProcess.SourceFile.ToProjectFile().IsValid())
            {
                return false;
            }

            IFile file = this.daemonProcess.SourceFile.GetPsiFile(CSharpLanguage.Instance);

            if (file == null)
            {
                return false;
            }

            bool hasErrorElements = new RecursiveElementCollector<ErrorElement>().ProcessElement(file).GetResults().Any();

            return !hasErrorElements;
        }

        #endregion
    }
}