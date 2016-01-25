#include "../inc/implementer.h"

int main() {
	/* Variable Declaration and Initialization */
	int buff_size = BUFFER_SIZE, i = 0;
	float *temp = NULL, *buffer = NULL;

	/* Memory Allocation */
	temp = malloc(buff_size * sizeof(float));
	buffer = malloc(buff_size * sizeof(float));

	/* Initialization */
	init();

	/* Main routine:
	 * Pulse
	 * Wait 66us
	 * Generate one ramp
	 * Do an acquisition (wait 100 us for simulation without acquisition)
	 */
	for(i = 0; i < 20000; i++) {
		pulse();
		usleep(66);
		ramp();
		usleep(100);
//		buffer = acquireADC(buff_size, temp);
	}

	/* RP and Variables Release */
	free(temp);
	free(buffer);

	/* End everything */
	end();

	return EXIT_SUCCESS;
}
