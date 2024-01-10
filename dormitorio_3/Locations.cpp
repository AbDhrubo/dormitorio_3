#include "Locations.h"
void Locations::resetClean_status() {
	for (int i = 0; i < l.size(); i++) {
		l[i].update_clean_status();
	}
}
