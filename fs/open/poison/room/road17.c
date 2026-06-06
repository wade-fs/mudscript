// Room: /open/poison/room/road17
inherit ROOM;

void create ()
{
  set ("short", "內庭");
  set ("long", @LONG
這裡是一個小庭院，院內種了許多梅花，好像是一個小
梅園般，微風輕拂，眼前一幅落花繽飛的景像，讓人很難想
像這會是人稱「魔教」的總壇所在地。
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "southeast" : __DIR__"road6",
  "west" : __DIR__"road16",
  "east" : __DIR__"room8",
]));
  set("outdoors", "/open/poison");

  setup();
}
