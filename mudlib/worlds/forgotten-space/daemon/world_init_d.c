// daemon/world_init_d.c
// 《遺忘的世界》(THE FORGOTTEN SPACE) 世界專屬初始化守護進程
// 由 /common/master.c 自動載入，啟動本書專屬之九城、區域、雙軌路網與事件守護進程

inherit "/std/object.c";

void create() {
    ::create();
    load_object("/secure/guild_d.c");
    load_object("/daemon/event_manager.c");
    load_object("/daemon/career_d.c");
    load_object("/daemon/mysteryd.c");
    load_object("/daemon/questd.c");
    load_object("/daemon/city_d.c");
    load_object("/daemon/tier3_d.c");
    load_object("/daemon/rumor_d.c");
    load_object("/daemon/region_d.c");
    load_object("/daemon/route_d.c");
}
