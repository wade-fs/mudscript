// /item/material/wolf_fur.c
inherit "/item/material/base_material";
void create() {
    ::create();
    set_name("狼皮");
    set_short("一張粗糙的狼皮");
    set_long("這是一張從野狼身上剝下來的皮，雖然有些血跡，但還算完整。\n");
    set_id(({"wolf fur", "fur", "狼皮"}));
    set_value(20);
}
