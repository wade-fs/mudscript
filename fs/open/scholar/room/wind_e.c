inherit ROOM;

void create ()
{
  set ("short", "東堂風");
  set ("long", @LONG
不知道是不是迷信的關係，總是聽到風聲呼呼的吹著，不禁讓人
好奇的想去查個究竟，好像是從書本後面傳過來的，難道書架後面有
個洞？還是耳朵有問題？
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"wind",
]));
  set("objects", ([ /* sizeof() == 1 */
  "/open/scholar/npc/scholar_wind.c" : 1,
]));

  setup();
}
