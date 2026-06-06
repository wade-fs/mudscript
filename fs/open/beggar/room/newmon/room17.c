inherit ROOM;

void create()
{
 set("short","臥室");
 set("long",@LONG
這裡是丐幫幫主的臥室，裡面看起來乾乾淨淨的，每樣東
西都是有條不紊的擺設整齊，不過上面卻積了一層薄薄的
灰塵，原來幫主是一個大老饕，只要一有時間就到外面去
尋找美食，甚少在這裡休息。
LONG);
 set("exits",([
 "south" : __DIR__"room22.c"
 ]));
 setup();
}
