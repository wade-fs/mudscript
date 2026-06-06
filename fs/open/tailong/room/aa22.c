inherit ROOM;

void create ()
{
  set ("short", "東院走廊");
  set ("long", @LONG
這裡是東院的中心點,同時也是個十字路口,西邊傳來了一些聲音,好像
有人在練武,而東邊卻是一片寧靜,不過好像有四個人影在那邊,你是否該過
去看看呢,牆上貼了一張紙(paper),你可以看看上面寫了什麼。
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"aa64",
  "south" : __DIR__"aa21",
  "north" : __DIR__"aa26",
  "east" : __DIR__"aa68",
]));
  set("item_desc", ([ /* sizeof() == 1 */
  "paper" : "
  東:玄機房(閒雜人等不得進入)
  西:武僧練習場
",
]));

  setup();
  replace_program(ROOM);
}
