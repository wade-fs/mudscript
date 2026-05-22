// /item/material/snake_venom.c
inherit "/item/material/base_material";
void create() {
    ::create();
    set_name("毒蛇牙");
    set_short("一對尖銳的毒蛇牙");
    set_long("這是一對帶有劇毒的蛇牙，頂端還殘留著透明的毒液。\n");
    set_id(({"snake venom", "fang", "蛇牙"}));
    set_value(25);
}
