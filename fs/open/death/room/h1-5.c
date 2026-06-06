// Room: /open/death/room/h1-5
inherit ROOM;

void create ()
{
  set ("short", "第一殿--補經所");
  set ("long", @LONG
你站在這裡，放眼望去，看到滿屋子都是和尚和道士，每個人都低
著頭，滿頭大汗的抄寫著經文，只見牆上寫著：『生前僧道傳道時故意
混水摸魚錯漏經文者，死後到此處抄寫經文，補回生前錯漏者，再發送
地獄受罪。』
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"h1-6",
  "south" : __DIR__"h1-9",
]));
  set("light_up", 1);

  setup();
}
