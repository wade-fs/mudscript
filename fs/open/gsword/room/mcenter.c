// Room: /d/oldpine/epath2.c

inherit ROOM;

void create ()
{
  set ("short", "蜀山奇陣之陣心");
	set( "build", 12 );
  set ("long", @LONG
所有的幻像向四周消逝了,你發現你處於一個奇異的房間,地上
有個巨大的太極圖,黑白分明繞著一座金爐(golden fireplace)旋
轉,四周的牆璧閃爍著七彩光芒,裊裊的清煙環繞四周,這就是蜀山
奇陣的陣心 ??
LONG);

  set("item_desc", ([ /* sizeof() == 1 */
  "golden fireplace" : "金爐上面刻著:
    夫五行者,變化生物之道,金克木,木克土,
    土克水,水克火,火克金.  蜀山奇陣,如此而已...
",
]));
  set("exits", ([ /* sizeof() == 1 */
  "out" : __DIR__"mroom6",
]));
  set("light_up", 1);

  setup();
}
