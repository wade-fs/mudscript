inherit ROOM;

void create ()
{
  set ("short", "瀑布");
  set ("long", @LONG
原來剛才的花啦聲是一道瀑布啊 ,抬頭看著這一洩千里的美景 ,
你突然發現似乎有一間小房子在瀑布源頭 ,低頭一看 ,又有一條
小路順著溪流而下 ,嗯 .....該往哪裡走好ㄋ ?

LONG);

  set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"room26",
  "northup" : __DIR__"room35",
  "northwest" : __DIR__"room37",
]));
  setup();
}


