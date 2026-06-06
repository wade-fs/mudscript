inherit ITEM;

void create()
{
        set_name("令牌", ({ "card" }) );
        set("unit", "張");
set("long", "這是一張沒什麼的令牌，或許\可以(show_card)給某些人看\n");
        set_weight(100);
        set("value",0);
}

