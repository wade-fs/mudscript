// Room: /u/o/ookami/teikei.c 
inherit ROOM;
 
void create ()
{
  set ("short", "帝國華擊團．花組．天龍寺分部");
  set ("long", @LONG
這裡是帝國華擊團花組的天龍寺分部,在你前面有一個石碑(stone)
,你可以看看上面寫些什麼,站在你面前的那個人就是帝國華擊團花組的
隊長,大神一郎
LONG);

  set("item_desc", ([ /* sizeof() == 1 */
  "stone" : "
天龍寺落成於民國87年8月9日
 由xboy監工
ookami負責修建
MADE IN TAIWAN
請大家愛用國貨
",
]));
  set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"aa41",
]));
  set("no_fight", 1);
  set("objects", ([ /* sizeof() == 1 */
  "/open/tailong/npc/ookami1.c" : 1,
]));
  set("no_magic", 1);
  set("valid_startroom", 2);

  setup();
  replace_program(ROOM);
}
