//vendor.c
#include "/open/open.h"
inherit F_VENDOR;

void create()
{
	set_name("店小二",({"vendor"}));
	set("gender", "男性" );
	set("age", 24);
set("long", @LONG
客棧店小二，他這邊賣的東西可多了。
LONG
	);
	set("combat_exp",10);
        set("attitude", "friendly");
        set("no_kill",1);
        set("no_fight",1);
        set("inquiry",([
                        "海皇" : "擁有不死之身的海皇，前次大戰之所以敗戰，據說是因為遭到封印的關係。",
                        "封印" : "好像是個能夠封鎖神明的神奇寶瓶。",
                        "神殿" : "舊神殿已毀，不過現在似乎有了新神殿，聽說還建得挺壯觀的。",
                       ]));
	set("vendor_goods", ({
                COMMON_OBJ"bandage",
                COMMON_OBJ"pill",
                COMMON_OBJ"pill1",
                COMMON_OBJ"pill2",
                COMMON_OBJ"plaster",
                COMMON_OBJ"plaster1",
                COMMON_OBJ"plaster2",
                COMMON_OBJ"plaster3",
                "/open/north-polar/obj/soup",
                "/open/north-polar/obj/bear-palm",
                "/open/doctor/pill/ff_pill",
                "/open/doctor/pill/ice_pill",
                "open/doctor/pill/f_pill",
                "/obj/example/chicken_leg",
	}) );
	setup();
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	switch( random(4) ) {
		case 0:
		say("店小二親切的說道: 這位"+RANK_D->query_respect(ob)+"是剛從外面進來吧，要不要先來杯薑湯驅驅寒氣呢!?\n");
			break;
		case 1:
                say("店小二喃喃道:聽說封印威力之所以減弱到能讓海王意識流動，是因為神殿年久失修、香火銳減所致。\n");
			break;
		case 2:
		say("店小二親切的說道:"+RANK_D->query_respect(ob)+"要不要嚐嚐本店特製的熊掌呢!?\n");
			break;
		case 3:
		say("店小二嘆了口氣:聽說海皇已經破除封印了，看來地上世界過不久就要沉入海底了。\n");
			break;
	}
}
