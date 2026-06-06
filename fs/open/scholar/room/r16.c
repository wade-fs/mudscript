// /u/j/judd/room/r16.c
inherit ROOM;

void create ()
{
  set ("short", "中堂西側");
  set ("long", @LONG
來到這裡，兩個大大的路標立在眼前....，寫的是草書，但仍可
看出北==>往火室圖書館，南==>往水室圖書館，儒門最有名的，就是
四大圖書館，風火土水，而你現在正在火與土的中間，你想先去看哪
一個呢？
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"r19.c",
  "north" : __DIR__"r13.c",
  "east" : __DIR__"w3.c",
]));
  set("light_up", 1);

  setup();
}
