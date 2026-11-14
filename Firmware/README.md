# Firebase setup notes

The schema is a proposed data shape. The rules are a restrictive starting example, not a complete production security design. Test rules in Firebase Emulator before deployment. Do not put service-account credentials or admin secrets in firmware or mobile app. Use per-device identity, TLS, rotation and server-side validation. Never enable public database access.
