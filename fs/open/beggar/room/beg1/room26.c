// Room: /u/g/guetenr/beggar/room/beg1/room26.c
inherit ROOM;

void create ()
{
  set ("short", "玄真寺");
  set ("long", @LONG
玄真寺雖小卻以寺中遍植牡丹芍藥而聞名江南，一到花季滿園姚黃魏紫
競豔，嬌紅嫩白爭芳，真真是人世春天莫過於此；古剎樸拙的牆垣更襯得眾
花燦爛絢麗，香風徐徐陣陣濃郁撲鼻，取次花叢真讓人疑似身在天上宮苑賞
玩呢；北邊的佛堂時而傳來誦經梵唄，正可沉澱紛紛心緒。

LONG);

  set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"room25.c",
]));
  set("outdoors", "/open/");
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/woman.c" : 1,
]));

  setup();
}
