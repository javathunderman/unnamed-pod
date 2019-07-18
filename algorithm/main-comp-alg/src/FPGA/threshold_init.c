#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "fpga_cache.h"

void populate_thresholds(Fpga *fpga, char *file_name) {
	FILE* stream = fopen(file_name, "r");

	char line[1024];
	/* removes the first line with headers */
	fgets(line, 1024, stream);

	/* loops through each threshold */
	while (fgets(line, 1024, stream)) {
		char *value;
		value = strtok(line, ",");

		uint8_t thresh_index;
		fxp32_16 thresh_minimum;
		fxp32_16 thresh_maximum;
		uint32_t thresh_persistence;
		uint32_t thresh_ratio;

		int i = 0;
		for (i = 0; i < 6; i++) {
			/* seperate based on comma */
			value = strtok(NULL, ",");
			char *end;
			/* functions used to set the fields of the data bus */
			if (i == 0) {
			}
			if (i == 1) {
				thresh_index = strtoul(value, &end, 10);
				write_thresh_write_index(fpga, thresh_index);
			}
			if (i == 2) {
				thresh_minimum = dtofxp(atof(value));
				write_thresh_new_min(fpga, thresh_minimum);
			}
			if (i == 3) {
				thresh_maximum = dtofxp(atof(value));
				write_thresh_new_max(fpga, thresh_maximum);
			}
			if (i == 4) {
				thresh_persistence = strtoul(value, &end, 10);
				write_thresh_persistence(fpga, thresh_persistence);
			}
			if (i == 5) {
				thresh_ratio = strtoul(value, &end, 10);
				write_thresh_f_ratio(fpga, thresh_ratio);
			}

		}
		write_thresh_latch_new(fpga, NiFpga_True);
		write_thresh_read_index(fpga, thresh_index);
		write_thresh_latch_new(fpga, NiFpga_False);
		if (fpga->cache.cur_thresh_index != thresh_index
				|| fpga->cache.cur_thresh_min != thresh_minimum
				|| fpga->cache.cur_thresh_max != thresh_maximum
				|| fpga->cache.cur_thresh_persistence != thresh_persistence
				|| fpga->cache.cur_thresh_ratio != thresh_ratio) {
		}
		refresh_cache(fpga);
	}
	fclose(stream);
}
