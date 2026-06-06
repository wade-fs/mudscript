inherit ROOM;
void create() {
	set( "short", "ω冥魔寶盒ω" );
	set( "exits", ([
		"out"       : "/open/clan/sky-wu-chi/room/room237",
	]) );
	set( "object", ([
		"file9"    : "/open/ghost-hole/obj/eq/ghost-leggings",
		"amount6"  : 1,
		"amount4"  : 1,
		"amount1"  : 1,
		"file4"    : "/open/ghost-hole/obj/eq/ghost-ring",
		"file3"    : "/open/ghost-hole/obj/eq/ghost-armor",
		"file2"    : "/open/ghost-hole/obj/eq/ghost-gloves",
		"file6"    : "/open/ghost-hole/obj/eq/ghost-belt",
		"file7"    : "/open/ghost-hole/obj/eq/ghost-cloak",
		"amount9"  : 1,
		"amount10" : 1,
		"amount5"  : 1,
		"amount8"  : 1,
		"file5"    : "/open/ghost-hole/obj/eq/ghost-helmet",
		"file1"    : "/open/ghost-hole/obj/eq/ghost-gem",
		"file8"    : "/open/ghost-hole/obj/eq/ghost-armband",
		"file10"   : "/open/ghost-hole/obj/eq/ghost-boots",
		"amount7"  : 1,
		"amount2"  : 1,
		"amount3"  : 1,
	]) );
	set( "owner", "cdrom" );
	set( "light_up", 1 );
	set( "build", 10107 );
	set( "long", @LONG
你讓自己的意識墮入黑暗深淵，誠心祈求邪靈庇護，冥魔戰甲由盒中緩緩浮升
你束上ω冥魔腰帶ω，凶邪魔妖的力量直接貫入丹田中。
你手持ω冥魔邪盾ω，銅牆鐵壁般的冥界之力護衛在前。
你套上ω冥魔指戒ω，惡魔力量開始注入已疲憊的身心。
你穿上ω冥魔足環ω，步法變得如陰夜風雲般詭譎無常。
你肇上ω冥魔脛甲ω，雙腿間湧入源源不絕的充沛魔力。
你戴上ω冥魔帝冠ω，突然只想瘋狂的沉醉於殺戮之中。
你穿上ω冥魔指套ω，魑魅魍魎的妖力皆匯聚於雙手上。
你戴上ω冥魔寶墜ω，內心得到了幽冥魔力的強力加持。
你穿起ω冥魔甲冑ω，感覺得到了刀槍不入的不死之驅。
你套上ω冥魔羽靴ω，身影猶如玄幻魔風般模糊了起來。
你戴上ω冥魔肩甲ω，一股凶惡的毀滅性力量環繞全身。
你披上ω冥魔披風ω，君臨天下的氣勢使世間魔物伏首。
你全力爆發冥魔戰甲的頂級力量，只見戰甲各部分均釋出無限妖力，注入你體內。
LONG);
	setup();
	replace_program(ROOM);
}
