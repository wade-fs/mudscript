// Room: /u/r/ranko/garden5.c
inherit ROOM;

void create ()
{
  set ("short", "毒園中央部份");
  set ("long", @LONG
此處所種的毒花,毒草等已屬平時所罕見.各種帶著絢麗色彩的
花朵在此爭奇鬥豔,教人看的目瞪口呆.其中,最引人注意的是生長在
當中的一朵血海棠(Blood flower),此株較尋常植物都要來的高大,顏
色也異常鮮豔,通體的火紅似是吸入了人血一般。
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"garden4-3.c",
]));
  set("item_desc", ([ /* sizeof() == 1 */
  "flower" : "一株巨大的血海棠,如此異物,想必吸引了不少稀世毒物於此棲息。
",
]));
  set("objects", ([ /* sizeof() == 3 */
  "/obj/source/green_snake.c" : 1,
  "/obj/source/poison_bird.c" : 1,
  "/obj/source/hundred_flower" : 1,
]));
  set("light_up", 1);

  setup();
}
