#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#define NUM_CHANNELS 14
#define JAM_DURATION 5

void print_banner() {
    printf("\n");
    printf("========================================\n");
    printf("       WiFi Jammer Simulation\n");
    printf("========================================\n");
    printf("WARNING: Actual WiFi jamming is illegal!\n");
    printf("This is a simulation only.\n");
    printf("========================================\n\n");
}

void simulate_scan() {
    printf("[+] Scanning for WiFi networks...\n");
    
    // Simulate scanning each channel
    for (int i = 0; i < 3; i++) {
        printf(".");
        fflush(stdout);
        usleep(500000); // 0.5 second delay
    }
    
    printf("\n\n");
}

void print_network_info(int channel, const char* ssid, int signal_strength) {
    printf("[+] Found network:\n");
    printf("    SSID: %s\n", ssid);
    printf("    Channel: %d\n", channel);
    printf("    Signal: %d%%\n", signal_strength);
    printf("\n");
}

void simulate_jam(int channel) {
    printf("[+] Simulating jamming on channel %d\n", channel);
    
    for (int i = 0; i < JAM_DURATION; i++) {
        printf("Sending deauth packets... ");
        
        // Simulate packet transmission
        for (int j = 0; j < 3; j++) {
            printf(".");
            fflush(stdout);
            usleep(200000); // 0.2 second delay
        }
        
        printf(" Done.\n");
        sleep(1);
    }
    
    printf("[!] Channel %d jammed successfully (simulation)\n\n", channel);
}

int main() {
    // Common WiFi channels (1-14)
    int channels[NUM_CHANNELS] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14};
    
    // Sample network SSIDs
    const char* ssids[] = {
        "HomeWiFi",
        "CoffeeShop",
        "OfficeNetwork",
        "PublicWiFi",
        "NeighborAP"
    };
    
    print_banner();
    
    // Simulate network scanning
    simulate_scan();
    
    // Seed random number generator
    srand(time(NULL));
    
    // Simulate finding 3 random networks
    for (int i = 0; i < 3; i++) {
        int channel = channels[rand() % NUM_CHANNELS];
        const char* ssid = ssids[rand() % 5];
        int strength = 60 + (rand() % 40); // Random strength 60-100%
        
        print_network_info(channel, ssid, strength);
    }
    
    printf("\n");
    
    // Simulate jamming on selected channels
    simulate_jam(6);  // Commonly used channel
    simulate_jam(11); // Another common channel
    
    printf("Simulation complete.\n");
    printf("Remember: Actual WiFi jamming is illegal!\n");
    
    return 0;
}