// Room: /u/r/red/room/flower.c
inherit ROOM;

void create ()
{
  set ("short", "南廂房");
  set ("long", @LONG
這是學識廳的南廂房，你可以看到學識廳的長老正坐在那邊
，看起來好像死了一般，真不知道他心理正在想些什麼東西，令
人心中不寒而慄。
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"e3.c",
]));
  set("objects", ([ /* sizeof() == 1 */
  "/open/scholar/npc/old_scholar.c" : 1,
]));

  setup();
}
