/*
 * Adds a mutex implementation based on c++ mutex to harfbuzz.
 */
#include <mutex>

using hb_mutex_impl_t = std::mutex;
#define HB_MUTEX_IMPL_INIT      UNUSED
#define hb_mutex_impl_init(M)   HB_STMT_START { new (M) hb_mutex_impl_t;  } HB_STMT_END
#define hb_mutex_impl_lock(M)   (M)->lock ()
#define hb_mutex_impl_unlock(M) (M)->unlock ()
#define hb_mutex_impl_finish(M) HB_STMT_START { (M)->~hb_mutex_impl_t(); } HB_STMT_END

#undef HB_NO_DRAW
#undef HB_NO_CFF
#undef HB_NO_OT_FONT_CFF
#undef HB_NO_FACE_COLLECT_UNICODES
#undef HB_NO_VAR
#undef HB_NO_METRICS
#undef HB_NO_NAME
#undef HB_NO_STYLE
#undef HB_NO_LAYOUT_FEATURE_PARAMS
#undef HB_NO_OT_KERN
#define HAVE_PTHREAD
#define HB_EXPERIMENTAL_API