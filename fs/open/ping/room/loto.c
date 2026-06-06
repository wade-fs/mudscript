inherit ROOM;
#include <ansi.h>

void create()
{
	set( "short", HIW + "【" + HIY + "狂想樂透彩券投注站" + HIW + "】" + NOR );
	set( "build", 1 );
	set( "long", @LONG

    這裡人來人往十分熱鬧, 每人手裡都拿著簽注單, 正專心地
選著自己的幸運號碼, 但也有些人拿著單子四處張望, 想要參考
別人的號碼, 這裡被擠的水洩不通, 你不禁想出去喘口氣, 結果
被一波一波的人潮擠的無法動彈, 大喊救命!
    旁邊有個小佈告欄(board)。

LONG);
	set("item_desc", ([
		"board" : "
	pick  <號碼> 購買彩券
	auto         快選五張彩券
	list  <期數> 查詢購買號碼
	claim <期數> 兌獎

	每天晚上九點準時開獎
	頭獎除獎金之外另附十名替身
",
	]) );
	set( "no_kill", 1 );
	set( "no_fight", 1 );
	set( "objects", ([
		"/u/a/acky/lotto/lotto" : 1,
	]) );
	set( "exits", ([
		"north" : __DIR__"road3",
	]) );
	setup();
}
