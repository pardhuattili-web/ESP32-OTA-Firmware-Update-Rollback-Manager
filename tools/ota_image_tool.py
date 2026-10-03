#!/usr/bin/env python3
import hashlib,json,sys
def main():
    if len(sys.argv)!=3:
        print("usage: ota_image_tool.py <firmware.bin> <version>");raise SystemExit(2)
    path,version=sys.argv[1:]
    data=open(path,"rb").read()
    print(json.dumps({"version":version,"size_bytes":len(data),"sha256":hashlib.sha256(data).hexdigest()},indent=2))
if __name__=="__main__": main()