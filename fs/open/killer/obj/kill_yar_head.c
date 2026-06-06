inherit ITEM;

void create()
{
        set_name("殺手所要的人頭", ({ "killer_wanted" }) );
        set("unit", "個");
        set("long", "這是曾經殺過YAR的的人頭？\n");
        set("no_sell",1);
        set_weight(10);
        set("value",0);
}
