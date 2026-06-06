inherit BANK;

void create ()
{
  set ("short", "錢莊");
  set ("long", @LONG
這是一個由木板組貼成的小屋子，你走進裡面，可以看到一個人
，正隔著木窗與你對望，其中，你也可以看到一些人正在這裡提領著
金錢。
    右邊牆角貼著一張說明書(sign)。
LONG);

set("item_desc",([
  "sign" : "這裡是錢莊﹐目前我們提供的服務有﹕

balance         查錢莊有多少存款
withdraw        領取存在錢莊的錢
deposit         把錢存進錢莊
convert         兌換錢幣。
lend            向錢莊借錢
relend          還錢給錢莊


balance
withdraw <數量> <種類>
deposit <數量> <種類> || deposit all
convert <數量> <貨幣> to <貨幣>

lend <數量> coin
relend <數量> coin


範例:       convert 10 silver to coin

錢幣種類有  1 gold == 100 silver == 10000 coin

",
]));
	set("evil_area",1);
	set("no_transmit",1);
	set("exits", ([ /* sizeof() == 1 */
"east" : __DIR__"a-04",
]));
	set("light_up", 1);
setup();
}
