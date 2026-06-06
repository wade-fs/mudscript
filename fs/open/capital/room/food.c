// Room: /open/capital/room/food
inherit ROOM;

void create ()
{
  set ("short", "王安食堂");
  set ("long", @LONG
京城數一數二的大食堂，據說老闆和乾通天很熟，才有機會把店面
開在這芝麻胡同上。這的大廚雖然沒有御廚那麼好的手藝，但是這兒的
烤鴨烤雞卻深受皇帝及達官貴人們的喜愛，所以這家食堂嚴然是貴族們
聚會宴客的場所，身上要是沒帶個百來兩銀子，還是別進來自討沒趣的
好。

LONG);

  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"h10",
]));
  set("objects", ([ /* sizeof() == 1 */
  "/open/capital/npc/redwaiter" : 1,
]));
  set("light_up", 1);

  setup();
}
