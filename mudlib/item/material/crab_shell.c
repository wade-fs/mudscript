// /item/material/crab_shell.c
inherit "/item/material/base_material";
void create() {
    ::create();
    set_name("螃蟹殼");
    set_short("一塊堅硬的螃蟹殼");
    set_long("這是一塊從泥螃蟹身上剝下來的殼，非常堅硬，或許可以用來加固防具。\n");
    set_id(({"crab shell", "shell", "螃蟹殼"}));
    set_value(15);
}
