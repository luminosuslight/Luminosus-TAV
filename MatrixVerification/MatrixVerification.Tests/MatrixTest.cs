// <copyright file="MatrixTest.cs">Copyright ©  2018</copyright>
using System;
using MatrixVerification;
using Microsoft.Pex.Framework;
using Microsoft.Pex.Framework.Validation;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace MatrixVerification.Tests
{
    /// <summary>Diese Klasse enthält parametrisierte Komponententests für Matrix.</summary>
    [PexClass(typeof(Matrix))]
    [PexAllowedExceptionFromTypeUnderTest(typeof(InvalidOperationException))]
    [PexAllowedExceptionFromTypeUnderTest(typeof(ArgumentException), AcceptExceptionSubtypes = true)]
    [TestClass]
    public partial class MatrixTest
    {
        /// <summary>Test-Stub für HsvToRgb(Single, Single, Single, Single&amp;, Single&amp;, Single&amp;)</summary>
        [PexMethod]
        public void HsvToRgbTest(
            [PexAssumeUnderTest]Matrix target,
            float h,
            float s,
            float v,
            out float r,
            out float g,
            out float b
        )
        {
            PexAssume.IsTrue(h >= 0.0f && h <= 1.0f);
            PexAssume.IsTrue(s >= 0.0f && s <= 1.0f);
            PexAssume.IsTrue(v > 0.0f && v <= 1.0f);

            target.HsvToRgb(h, s, v, out r, out g, out b);

            PexAssert.IsTrue(r >= 0.0f && r <= 1.0f);
            PexAssert.IsTrue(g >= 0.0f && g <= 1.0f);
            PexAssert.IsTrue(b >= 0.0f && b <= 1.0f);
            // TODO: Assertionen zu Methode MatrixTest.HsvToRgbTest(Matrix, Single, Single, Single, Single&, Single&, Single&) hinzufügen
        }
    }
}
