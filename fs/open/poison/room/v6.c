// Room: /open/poison/room/v6.c
inherit ROOM;

void create ()
{
  set ("short", "豬舍");
  set ("long", @LONG
一間以磚砌成的豬舍，地上鋪上了泥漿供豬隻們打滾，泥漿中
混雜了豬糞和一些不知名了穢物，臭氣薰天，讓人聞了噁心不已。
這裡養了各式各樣的豬隻，黑豬、白豬、公豬、母豬、小豬，每一
隻都是懶洋洋的躺在泥巴中休息，有幾隻豬因你的到來而抬起頭來
看看，但發覺你手中沒有食物便又低下頭睡覺去了。
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"v2-8.c",
]));
  set("light_up", 1);
  set("objects", ([ /* sizeof() == 3 */
   "/open/poison/npc/pig3.c" : 2,
  "/open/poison/npc/pig2.c" : 1,
   "/open/poison/npc/pig1.c" : 1,
]));

  setup();
}
