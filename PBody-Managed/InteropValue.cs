namespace PBody.Managed;

/// <summary>
/// A Struct that can be safetly passed to/from unmanaged code.
/// </summary>
public struct InteropValue
{
    public int? Int;
    public float? Float;
    public double? Double;
    public bool? Bool;
    public IntPtr? IntPtr;
}
