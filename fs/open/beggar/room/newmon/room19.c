inherit ROOM;

void create()
{
 set("short","廚房");
 set("long",@LONG
一走進這裡，你就聞到陣陣的黴味，還有幾隻老鼠在你腳
下跑來跑去。煮菜的鐵鍋鏟子掉在地上，看起來似乎有好
幾年沒有人用過這些器具了。這也難怪，因為乞丐總是向
人乞討食物來填飽肚子，誰會無聊到捲起袖子在這裡煮菜
呢？

LONG);
 set("exits",([
 "east" : __DIR__"room20.c"
 ]));
 setup();
}
