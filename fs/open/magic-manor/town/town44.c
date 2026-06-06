inherit ROOM;
#include <ansi.h>

void create ()
{
        set ("short", "密林");
	set( "build", 1 );
        set ("long", @LONG
從小森林走來的景象一比，兩旁的小林木不知何時已經換成高聳
入雲的百年古木了，樹葉漫天遮蔭，樹林裏的光線也愈來愈微弱了，
兇猛的野獸叫聲就在不遠處傳來，詭異的氣氛也愈來愈濃厚了。

你可以在路旁看到一張告示牌(sign)。

LONG);  

	set("item_desc",([
	"sign" : "\n\t前\t凡\n\t面\t風\n\t的\t雲\n\t森\t鎮\n\t林\t民\n\t極\t皆\n\t度\t不\n\t的\t得\n\t危\t進\n\t險\t入\n\t，\t!!\n"
	]));

        set("exits", ([ /* sizeof() == 4 */
        "east"	: __DIR__"town45",
        "west"	: __DIR__"town43",
	]));

        setup();
}
