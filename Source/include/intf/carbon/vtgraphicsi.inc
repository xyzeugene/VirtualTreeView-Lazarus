uses
  CarbonDef, CarbonCanvas, MacOSAll, CarbonProc, LCLProc;

//todo: properly implement
procedure AlphaBlend(Source, Destination: HDC; const R: TRect; const Target: TPoint; Mode: TBlendMode; ConstantAlpha, Bias: Integer);
var
  SrcDC: TCarbonDeviceContext absolute Source;
  DestDC: TCarbonDeviceContext absolute Destination;
begin
  case Mode of
    bmConstantAlpha,
    bmPerPixelAlpha,
    bmMasterAlpha,
    bmConstantAlphaAndColor:
      begin
        CGContextSetBlendMode(DestDC.CGContext, kCGBlendModeNormal);
        CGContextSetRGBFillColor(DestDC.CGContext, (Bias and $000000FF) / 255,
            ((Bias shr 8) and $000000FF) / 255,
            ((Bias shr 16) and $000000FF) / 255,
            ConstantAlpha / 255);

        CGContextFillRect(DestDC.CGContext, GetCGRect(R.Left + Target.x, R.Top + Target.y,
            R.Right - R.Left, R.Bottom - R.Top));
      end;
  end;
end;

function CalculateScanline(Bits: Pointer; Width, Height, Row: Integer): Pointer;
begin
  Result := nil;
end;

function GetBitmapBitsFromBitmap(Bitmap: HBITMAP): Pointer;
begin
  Result := nil;
end;
