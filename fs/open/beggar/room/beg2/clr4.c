// Room: /u/g/guetenr/beggar/room/beg2/clr4.c
inherit ROOM;

void create ()
{
  set ("short", "蒼鬱林道");
  set ("long", @LONG
但見銀白的激流在林道前沖劃出一個淺灘，泠泠的水聲在空中不停地迴
響。淺灘上一名老叟頭戴斗笠靜坐於此垂釣，身邊的小僮在一旁升火溫酒，
還不時逗弄著江畔的魚鷹，林道的榆樹下一頭青驢正專心地啃食著嫩草。晨
間的輕風微拂，一瞬間恍若踏進了世外桃源。
LONG);

  set("outdoors", "/open/");
  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"clr3.c",
  "north" : __DIR__"clr5.c",
]));
  set("objects", ([ /* sizeof() == 1 */
  "/open/beggar/room/beg1/npc/lv1beg.c" : 2,
]));

  setup();
}
