// daemon/world_init_d.c
// Fantasy Space (fsmud) 世界專屬初始化守護進程
// 由 mudlib/common/master.c 自動載入，啟動本世界專屬之戰鬥、公會、銀行、星際、事件與聚落守護進程

inherit "/std/object.c";

void create() {
    ::create();
    load_object("/secure/guild_d.c");
    load_object("/secure/combat_d.c");
    load_object("/secure/skill_d.c");
    load_object("/secure/party_d.c");
    load_object("/secure/pk_d.c");
    load_object("/secure/bank_d.c");
    load_object("/secure/map_d.c");
    load_object("/secure/dist_d.c");
    load_object("/secure/crafting_d.c");
    load_object("/secure/interstellar_d.c");
    load_object("/secure/home_d.c");
    load_object("/secure/event_d.c");
    load_object("/daemon/timeline_d.c");
    load_object("/daemon/settlement_d.c");
    load_object("/daemon/footprint_d.c");
}
