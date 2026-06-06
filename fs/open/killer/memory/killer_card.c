inherit ITEM;

void create()
{
        set_name("殺手密令", ({ "killer_card" }) );
        set("unit", "張");
        set("long", "這是傳說中，黑牙聯特級殺手的令牌，想不到你居然會有？\n");
        set("no_sell",1);
        set("no_give",1);
        set_weight(10);
        set("value",0);
}

int query_autoload ()
{
 if (this_player() && this_player()->query("quest/memory") == 1)
    return 1;
  return 0;
}  
