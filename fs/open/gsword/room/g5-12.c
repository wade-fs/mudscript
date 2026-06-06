// Room: /open/gsword/room/wghouse1.c
inherit ROOM;

void create ()
{
  set ("short", "藏經閣");
  set ("long", @LONG
這是仙劍派用以典藏武學秘笈之處，據說只有經過掌門人的許可，才
可到此翻閱武功秘笈，因此地上積了一層厚厚的灰塵，連秘笈由於年代久
遠，也是殘破不全，在左邊的一角，有一個特別老舊的書架(shelf)。
 
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "west" : "/open/gsword/room/g5-11.c",
]));
  set("objects",([
"/open/gsword/npc/bookkeeper" :1 ]));

  set("light_up", 1);
  set("item_desc",([
 "shelf": "一個老舊的書架 ,上邊擺\著數本殘破不全的書籍 ,好像寫著『仙劍密笈』幾個字\n"
  ]));
  setup();
}
