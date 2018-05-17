using System;

namespace WinFormBluetoothInputDeviceMainProject.Domain
{
    /// <summary>
    /// 鍵盤動作標籤
    /// </summary>
    [Flags()]
    public enum KeyboardFlag : int
    {
        ExtendedKey = 1,
        KeyUp = 2,
        Unicode = 4,
        Scancode = 8
    }
}