inherit ROOM;

void create ()
{
  set ("short", "前庭");
  set ("long", @LONG
這兒是前庭的一個角落, 四周栽種了各式各樣的奇花異草, 有
些花卉甚至連皇宮也沒有, 你看到這些奇花異草, 真想摘一把帶回
家種, 然而一想到段家高手眾多, 就不由得打消了這個念頭......

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"np9",
  "east" : __DIR__"np4",
]));
  set("light_up", 1);

  setup();
  replace_program(ROOM);
}
