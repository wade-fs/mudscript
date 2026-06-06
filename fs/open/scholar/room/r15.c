// /u/j/judd/room/r15.c
inherit ROOM;

void create ()
{
  set ("short", "中堂東側");
  set ("long", @LONG
來到此處，只見一個指向東北方箭標畫在牆上==>>風室圖書館，
而地上有一條亮白色的道路通往東北方，到底儒門的四大圖書館各有
什麼不同，只有全部都看過了才會知道，也許風室圖書館會有教人如
何借東風的方法也說不定.........
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"r11.c",
  "south" : __DIR__"r18.c",
]));
  set("light_up", 1);

  setup();
}
