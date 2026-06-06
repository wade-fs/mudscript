inherit ROOM;

void create ()
{
  set ("short", "西院走廊");
  set ("long", @LONG
這裡是西院的中心點,同時也是個十字路口,東邊傳來了一些聲音,好像
有人在練武,而西邊卻是一片寧靜,隱隱透著一股強而有力的氣,不知道那裡
是否有著什麼武林高手,牆上貼了一張紙(paper),你可以看看上面寫了什麼。
LONG);

  set("item_desc", ([ /* sizeof() == 1 */
  "paper" : "
  東 : 武僧練習場
  西 : 牟尼堂(閒雜人等,不得進入)
",
]));
  set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"aa17",
  "south" : __DIR__"aa15",
  "north" : __DIR__"aa19",
  "east" : __DIR__"aa60",
]));

  setup();
  replace_program(ROOM);
}
