﻿
using System.Runtime.CompilerServices;

[assembly: InternalsVisibleTo("protobuf-net.Test, PublicKey="
    + "002400000480000094000000060200000024000052534131000400000100010009ed9caa457bfc"
    + "205716c3d4e8b255a63ddf71c9e53b1b5f574ab6ffdba11e80ab4b50be9c46d43b75206280070d"
    + "dba67bd4c830f93f0317504a76ba6a48243c36d2590695991164592767a7bbc4453b34694e31e2"
    + "0815a096e4483605139a32a76ec2fef196507487329c12047bf6a68bca8ee9354155f4d01daf6e"
    + "ec5ff6bc")]

#if NET20 || NET35
namespace System.Diagnostics.CodeAnalysis
{
    // make NerdBank happy (the generated code doesn't anticipate people using frameworks this old)
    [System.AttributeUsage(System.AttributeTargets.Assembly | System.AttributeTargets.Class | System.AttributeTargets.Constructor | System.AttributeTargets.Event | System.AttributeTargets.Method | System.AttributeTargets.Property | System.AttributeTargets.Struct, AllowMultiple = false, Inherited = false)]
    internal sealed class ExcludeFromCodeCoverageAttribute : Attribute { }
}
#endif