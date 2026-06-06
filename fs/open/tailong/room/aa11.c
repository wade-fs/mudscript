inherit ROOM;

void create ()
{
  set ("short", "走道");
  set ("long", @LONG
一走到這裡,往四面望去,只看到四周種滿了林樹,枝頭鳥兒高聲歌唱
,好一幅悠閒的風景畫,頓時讓你覺得心曠神怡,而在樹林後面隱約有著一
座高塔,不知道裡面有著什麼東西
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"aa9",
  "west" : __DIR__"aa13",
]));
}
