// /item/material/wood.c
inherit "/item/material/base_material";
void create() {
    ::create();
    set_name("木材");
    set_short("一塊紮實的木材");
    set_long("一塊質地堅硬的木材，可以用來製作簡易的裝備。\n");
    set_id(({"wood", "木材"}));
    set_value(5);
}
