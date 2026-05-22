// /item/material/slime_jelly.c
inherit "/item/material/base_material";
void create() {
    ::create();
    set_name("史萊姆黏液");
    set_short("一團綠色的史萊姆黏液");
    set_long("這是一團黏糊糊的液體，散發著微弱的酸味。\n");
    set_id(({"slime jelly", "jelly", "黏液"}));
    set_value(15);
}
