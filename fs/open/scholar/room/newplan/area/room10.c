// Room: /u/s/sueplan/newplan/area/room10
inherit ROOM;

void create ()
{
  set ("short", "天相星");
  set ("long", @LONG
    紂王手下有許多忠臣，其中有一位聞太師，卻是不能被遺忘的
存在。『太師』即為首相，如我國的行政院長。聞太師不但掌握全國行
政，而且兼任大元帥。
    可足聞太師在殷、周最後一場大決戰中，被周軍功擊攻擊而戰死。
太白金星感動他的忠勇精神，就引魂到天界，請他永住天相星。

LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/open/scholar/room/newplan/npc/scholar_houng.c" : 1,
]));
  set("no_transmit", 1);
  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"room9.c",
  "陣心" : __DIR__"jroom.c",
]));

  setup();
}
int valid_leave(object me, string dir)
{
  if(dir=="陣心"&&present("scholar",environment(me)))
  {
  return notify_fail("你發覺有人擋在你面, 不讓你過!!!\n");
  }
  return 1;
}
