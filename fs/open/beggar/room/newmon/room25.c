inherit ROOM;

void create()
{
 set("short","藏經閣");
 set("long",@LONG
此地是丐幫保存重要書籍的地方，書架上滿滿的都是書，
不知道有沒有「降龍十八掌」跟「打狗棒法」的秘笈呢？

LONG);
 set("exits",([
 "west" : __DIR__"room24.c"
 ]));

setup();
}
