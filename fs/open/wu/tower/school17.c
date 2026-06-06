// Room: /open/wu/room/school17
inherit ROOM;

void create ()
{
  set ("short", "青雲居");
  set ("long", @LONG
走進這裡，你看到有個人正埋首書堆，完全無視你的到來。你看到這房間
到處都堆滿了書籍，連一張床也沒有，仔細一瞧，你可以在牆角發現一條睡覺
用的被子，被子旁邊還有一個咬剩的包子，以及一瓶半滿的清水。假如你仔細
注意一下，你會發覺東邊書架後有一個不起眼的窗戶。
LONG);
  set("item_desc", ([ /* sizeof() == 1 */
  "window" : "    一個木框小窗，你有一點點想跳出去看看外頭有些什麼！\n",
]));

  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"school16",
]));
  set("objects", ([ /* sizeof() == 1 */
  "/open/wu/npc/trainer2.c" : 1,
]));
  set("light_up", 1);

  setup();
}

void init() {
   add_action("do_jump","jump");
}
int do_jump(string str) {
     if(str != "window"){
        tell_object(this_player(),"你要從哪兒跳出去啊？\n");
        return 1;}
     else {
        tell_object(this_player(),"你往窗外奮力一跳～～。\n");
        this_player()->move(__DIR__"road1");
        return 1;}
}
