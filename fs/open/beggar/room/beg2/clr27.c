// Room: /u/g/guetenr/beggar/room/beg2/clr27.c
inherit ROOM;

void create ()
{
  set ("short", "廚房");
  set ("long", @LONG
一走進這裡，你就聞到陣陣的黴味，還有幾隻老鼠在你腳
下跑來跑去。煮菜的鐵鍋鏟子掉在地上，看起來似乎有好幾年
沒有人用過這些器具了。這也難怪，因為乞丐總是向人乞討食
物來填飽肚子，誰會無聊到捲起袖子在這裡煮菜呢？

LONG);

  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"clr25.c",
]));
  set("objects", ([ /* sizeof() == 1 */
  "/u/g/guetenr/beggar/npc/man2.c" : 1,
]));

  setup();
}
