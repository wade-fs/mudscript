// /item/newbie_statue.c
inherit "/std/item";

void create() {
    ::create();
    set_name("勇者雕像");
    set_short("一座宏偉的勇者雕像");
    set_long("這是一座純金鑄造的雕像，刻畫著傳說中拯救世界的英雄。\n基座上刻著：『勇氣是通往偉大之路的第一步。』\n");
    set_id(({"statue", "雕像"}));
    
    set_no_get(1);        // 搬不動
    set_indestructible(1);// 砸不壞
    set_weight(1000000);
}
