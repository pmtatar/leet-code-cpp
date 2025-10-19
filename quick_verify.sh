#!/bin/bash

# Quick Build Verification - Simple and Fast
# Output is logged to verify_log.txt

LOG_FILE="verify_log.txt"

# Function to output to both console and log file
log() {
    echo "$@" | tee -a "$LOG_FILE"
}

# Clear the log file
> "$LOG_FILE"

log "🔨 Quick C++ Build Verification"
log "================================"
log "Started at: $(date)"
log ""

total=0
success=0
failed=0

while IFS= read -r file; do
    ((total++))
    if g++ -std=c++17 -Wall -Wextra "$file" -o /dev/null 2>/dev/null; then
        log "✓ $file"
        ((success++))
    else
        log "✗ $file"
        ((failed++))
        # Log error details
        g++ -std=c++17 -Wall -Wextra "$file" -o /dev/null 2>&1 | head -5 | while read -r line; do
            log "  $line"
        done
    fi
done < <(find . -name "*.cpp" -type f | sort)

log ""
log "================================"
log "Total: $total | Success: $success | Failed: $failed"
log "Success Rate: $((success * 100 / total))%"
log ""

if [ $failed -eq 0 ]; then
    log "✓ All files compile successfully!"
else
    log "⚠️  Some files failed to compile"
    log ""
    log "Failed files:"
    grep "^✗" "$LOG_FILE" | sed 's/^/  /'
fi

log ""
log "Completed at: $(date)"
log ""
log "📄 Full log saved to: $LOG_FILE"
